#
# BIG THANKS TO https://github.com/amalliar/colorised-norminette
# FORKED FROM https://github.com/liftchampion/colorised_Norminette
#

NORM_COLOR=10
NO_NORM_COLOR=9

#python -m norminette "$@" 2>/dev/null | awk -v nc="$NORM_COLOR" -v nnc="$NO_NORM_COLOR" '
norminette "$@" | awk -v nc="$NORM_COLOR" -v nnc="$NO_NORM_COLOR" '
BEGIN {
    nc = "\x1b[38;5;" nc "m"
    nnc = "\x1b[38;5;" nnc "m"
    noc = "\x1b[0m"
}
{
    output = $0
    if (output ~ /OK!/)
        print nc "[NORME OK]" noc
    else if (output ~ /Error!/)
        print nnc "[NORME KO]" noc
    else if (output ~ /no such file or directory/)
		print output > "/dev/stderr"
    else
        print output > "/dev/stderr"
}
'
