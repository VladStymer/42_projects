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


def run_command(command, executable):
    proc = subprocess.Popen(
            command,
            stdout=subprocess.PIPE,
            stdin=subprocess.PIPE,
            stderr=subprocess.PIPE,
            shell=True,
            executable=executable
    )
    try:
        proc.wait(timeout=5)
    except subprocess.TimeoutExpired:
        print("Process timed out: ", proc)
        proc.kill()
        return {'code': None, 'out': None, 'err': None}
    code = proc.returncode
    o, e = proc.communicate()
    out = o.decode()
    err = e.decode()
    return {
        'code': code,
        'out': out,
        'err': err,
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
    }
    for key, (bash, minishell) in both_results.items():
        if bash != minishell:
            ok = False
            print(f"{key}:\n\tbash: {bash}\n\tminishell: {minishell}")
    return ok

def run_in_bash(command):
    bash_exec = "/usr/bin/bash"
    attrs = run_command(command, bash_exec)
    if attrs['err']:
        attrs['err'] = attrs['err'].removeprefix(f"{bash_exec}: ").removeprefix("line 1: ")
    #print('bash:', attrs)
    return attrs

def run_in_minishell(command):
    minishell_exec = "./minishell"
    attrs = run_command(command, minishell_exec)
    if attrs['err']:
        attrs['err'] = attrs['err'].removeprefix(f"minishell: ")
    #print('minishell:', attrs)
    #print("OUTPUT:\n", attrs['out'])
    return attrs

def run_commands(commands):
    for cmd in commands:
        print(cmd)
        ok = check(
            run_in_bash(cmd),
            run_in_minishell(cmd),
        )
        print(f"{colors.OKGREEN}OK{colors.NC}" if ok else f"{colors.FAIL}KO{colors.NC}")
        print("\n\n")

def test_simple_commands():
    commands = [
        "echo 'hello world'",
        "env | grep HOME",
		"$? + $?",
		"echo $? + $?",
		"cat lol.c | cat > lol.c",
		"echo '$USER'",
		"cd .",
		"cd ..",
		"pwd",
		"pwd .",
		"pwd ..",
		"ls",
		"wc Makefile",
		"unset PATH",
		"ls",
		"wc Makefile",
		"cat file | grep bla | more",
		"ls fichiernul | grep bla | more",
		"cat | cat | ls",
		"echo $HOME",
		'echo "$HOME"',
		"echo '$HOME'",
		'echo "$USER"',
		"DOWN",
		"env | grep HO > tatata | < jajaj cat",
        "ls | > tututu",
        "echo '",
		"sleep 2 | echo done",
        "echo |",
        "echo | |",
        "| | echo",
        "| echo",
        "echo hello | cat > test < ./.gitignore > gagag | > tests | |",
    ]
    run_commands(commands);

def main() -> int:
    test_simple_commands()
    return 0

if __name__ == '__main__':
    sys.exit(main())
