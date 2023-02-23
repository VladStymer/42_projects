#!/bin/bash

make ${PWD##*/}-test &&

#colors
black='\033[30m'
red='\033[31m'
green='\033[0;32m'
yellow='\033[33m'
blue='\033[34m'
magenta='\033[0;35m'
cyan='\033[36m'
white='\033[37m'
#style
bold='\033[1m'
dim='\033[2m'
underline='\033[4m'
blink='\033[5m'
reverse='\033[7m'
hidden='\033[8m'
reset='\033[0m'

test_builtin()
{
    builtin_name=$1
    shift # retire le nom du built-in des arguments
    arguments=("$@") # récupère tous les autres arguments dans un tableau

    echo -e "${magenta}$builtin_name is runing${reset}\n"
    i=1
    while [ $i -lt ${#arguments[@]} ]
    do
        argument=${arguments[$((i - 1))]}
        if [ -z "$argument" ]
        then
            minishell_output=$(./builtins-test "$builtin_name")
			minishell_exit_code=$?
            bash_output=$("$builtin_name")
            bash_exit_code=$?
        else
            minishell_output=$(./builtins-test "$builtin_name" "$argument")
			minishell_exit_code=$?
			mini_pwd=$(pwd)
            bash_output=$("$builtin_name" "$argument")
            bash_exit_code=$?
			bash_pwd=$(pwd)
        fi
		echo -e "${underline}${yellow}ARGUMENT${reset} 		= $argument"
        echo "minishell		= $minishell_output"
        echo "bash			= $bash_output"
		if [ "$builtin_name" = "cd" ]
		then
			bash cd.sh $bash_pwd $mini_pwd
		fi
		if [ "$builtin_name" = "export" ]
		then
			echo $(export) | grep "$argument"
			echo $(./builtins-test "export") | grep $argument
		fi 
		diff -u <(echo "$bash_output") <(echo "$minishell_output")
        if [ $? -eq 0 ]
        then
            printf "${green}Les sorties sont identiques.${reset}\n\n"
        else
            printf "${red}Les sorties sont différentes.${reset}\n\n"
        fi
        echo "m exit code		= $minishell_exit_code"
        echo "b exit code		= $bash_exit_code"
		diff -u <(echo "$bash_exit_code") <(echo "$minishell_exit_code")
		if [ $? -eq 0 ]
        then
            printf "${green}exit code identiques.${reset}\n\n"
        else
            printf "${red}exit code différentes.${reset}\n\n"
        fi
        i=$((i + 1))
		printf "\n\n\n"
    done
    printf "\n\n\n"
}

if (( $# >= 1 )); then
	./test.py
	exit
fi

while true; do
	echo -e "${yellow}\nSélectionnez une option :${reset}"
	echo " cd"
	echo " echo"
	echo " env"
	echo " exit"
	echo " export"
	echo " pwd"
	echo " unset"
	printf "${bold}"
	echo " all"
	printf "${reset}"
	printf "${cyan}"
	echo " make"
	echo " quit"
	printf "${yellow}Que veux-tu tester ? : ${reset}"
	read input
	printf "\n"
	case $input in
		cd)
			test_builtin cd "" "~" "~lol" "~/Documents/RENDU/" .. /src/ "~/Documents/minishell" "~/Documents/minishell/project.config.mk" "~/Documents/noaccesdirectori" \
				"$(printf 'a%.s' {1..300})" end
			;;
		echo)
			test_builtin echo "" "jean jacques" "-n" "hello!" "hello\nworld" "22" "3.3" "#" "true" end
			;;
		env)
			test_builtin env "" "aaaa" INVALID_VARIABLE "foo bar" --invalid-option end
			;;
		exit)
			test_builtin exit "" 0 1 2 foo -1 3 end
			;;
		export)
			test_builtin "export" "" "VAR=value" "VAR2=value2" "VAR=" "VAR2=" "VAR=value VAR2=value2" end
			;;
		pwd)
			test_builtin pwd ""
			;;
		unset)
			test_builtin unset "" "VAR" "VAR VAR2" VAR_INEXISTANTE end
			;;
		all)
			test_builtin cd "" "~" "~lol" "~/Documents/RENDU/" .. /src/ "~/Documents/minishell" "~/Documents/minishell/project.config.mk" "~/Documents/noaccesdirectori" \
				"$(printf 'a%.s' {1..300})" end
			test_builtin echo "" "jean jacques" "-n" "hello!" "hello\nworld" "22" "3.3" "#" "true" end
			test_builtin env "" "aaaa" INVALID_VARIABLE "foo bar" --invalid-option end
			test_builtin exit "" 0 1 2 foo -1 3 end
			test_builtin "export" "" "VAR=value" "VAR2=value2" "VAR=" "VAR2=" "VAR=value VAR2=value2" end
			test_builtin pwd ""
			test_builtin unset "" "VAR" "VAR VAR2" VAR_INEXISTANTE end
			if [ $? -ne 0 ]
			then
				printf "${red}La compilation a échoué.${reset}\n\n"
			else
				printf "${green}La compilation a réussi.${reset}\n\n"
			fi
			;;
		make)
			make fclean
			make 
			if [ $? -ne 0 ]
			then
				printf "${red}La compilation a échoué.${reset}\n\n"
			else
				printf "${green}La compilation a réussi.${reset}\n\n"
			fi
			;;
		quit)
			exit 0
			;;
		*)
			printf "${red}Option non valide.${reset}\n\n"
			;;
	esac
done
