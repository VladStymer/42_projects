#!/usr/bin/env python3

import subprocess
import sys
import os
import re
from pprint import pprint

class colors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    NC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

def get_content(output, tag):
    matching = re.findall(f"<{tag}>(.*?)</{tag}>", output, flags=re.M | re.DOTALL)
    if not matching:
        return None
    return matching[0]


def run_command(argv, **popen_args):
    proc = subprocess.Popen(
            argv,
            stdout=subprocess.PIPE,
            stdin=subprocess.PIPE,
            stderr=subprocess.PIPE,
            **popen_args,
    )
    if type(argv) == str:
        print(argv.split('\n')[2].strip())
    try:
        proc.wait(timeout=5)
    except subprocess.TimeoutExpired:
        print(proc)
        proc.kill()
    c = proc.returncode
    o, e = proc.communicate()
    o = o.decode()
    err = e.decode()
    return {
        'code': get_content(o, "code"),
        'out': get_content(o, "out"),
        'err': err,
        'cwd': get_content(o, "cwd"),
    }

def check(bash_result, minishell_result):
    ok = True
    both_results = {
        "code": (
            bash_result['code'],
            minishell_result['code']
        ),
        "out": (
            bash_result['out'],
            minishell_result['out']
        ),
        "err": (
            bash_result['err'],
            minishell_result['err']
        ),
        "cwd": (
            bash_result['cwd'],
            minishell_result['cwd']
        ),
    }
    for key, (bash, minishell) in both_results.items():
        if bash != minishell:
            ok = False
            print(f"{key}:\n\tbash: {bash}\n\tminishell: {minishell}")
    return ok

def run_in_bash(argv):
	commands = f"""
	echo -n "<out>"
	{' '.join(argv)}
	echo "</out><code>$?</code><cwd>`pwd`</cwd>"
	"""
	bash_exec = "/Users/vnicoud/.brew/bin/bash"
	attrs = run_command(commands, shell=True, executable=bash_exec)
	if attrs['err']:
		attrs['err'] = attrs['err'].removeprefix(f"{bash_exec}: ").removeprefix("line 3: ")
	else:
		attrs['err'] = None
	return attrs

def run_in_minishell(argv):
	stripped_argv = list()
	for arg in argv:
		stripped_argv.append(arg.strip("\"'"))
	attrs = run_command(['./builtins-test', *stripped_argv])
	if attrs['err']:
		attrs['err'] = attrs['err'].removeprefix(f"minishell: ")
	else:
		attrs['err'] = None
	return attrs


def run_commands(cmd_name, args_list):
    for args in args_list:
        cmd = [cmd_name, *args]
        ok = check(
            run_in_bash(cmd),
            run_in_minishell(cmd),
        )
        print(f"{colors.OKGREEN}OK{colors.NC}" if ok else f"{colors.FAIL}KO{colors.NC}")
        print("\n\n")


def test_cd():
    test_forbidden_dir = "./test_files/cd_no_perm"
    os.makedirs(test_forbidden_dir, mode=0o000, exist_ok=True)
    test_args = [
		# Empty "should cd $HOME"
		[], ["''"],

		# Relative paths
		["src"], ["./src"],
		["./sdfgsdgs"], # No such file or directory

		# . and ..
		["."], [".."], ["/.."], ["/."],

		# Absolute paths
		["/"], ["/home"],

		["/sdfgsdgs"], # No such file or directory
		["sdfgsdgs"], # No such file or directory
		
		# Wrong path
		["~lol"], # No such file or directory
		["~/.bashrc"], # Not a directory
		["~/.zshrc"], # Not a directory

		# Long file name (usually max 255 chars)
        ['a' * 254],
        ['a' * 255],
        ['a' * 256],

		# Other errors
		["too_many", "args"], # too many arguments
		[test_forbidden_dir], # Permission denied
    ]
    run_commands('cd', test_args)

def test_echo():
    test_args = [
		# Empty should return empty line
		[], ["''"],

		# Should return nothing with -n
		['-n'], ['-n', "''"],

        # Single word
        ['"hello world"'],

        # -n option
        ['-n', '"hello world"'], ['--n', 'hello', 'world'], ['---n', '"hello world"'],
        ['-nn', '"hello world"'], ['-nnn', 'hello', 'world'], ['---nnnn', '"hello world"'],

        # Multiple words
        ["hello", "world"],

        # A lot of words
        ["hello" for i in range(100)],
    ]
    run_commands('echo', test_args)


def main() -> int:
    test_cd()
    test_echo()
    return 0

if __name__ == '__main__':
    sys.exit(main())

