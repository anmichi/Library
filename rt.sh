g++-14 -O2 -std=gnu++23 -o main $1
g++-14 -O2 -std=gnu++23 -o naive $2
while true; do
  python3 gen.py > in.txt
  ./main < in.txt > out1.txt
  ./naive < in.txt > out2.txt
  if ! diff out1.txt out2.txt; then
    echo "found"
    break
  fi
  echo "match"
done