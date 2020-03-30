BAC=lu
FLG=
echo "=== `date` build host"
uname -a
echo "=== `date` start basic ${BAC} test"
./${BAC} ${FLG}
XS=$?
echo "=== `date` e_n_d basic ${BAC} test"
exit $XS
