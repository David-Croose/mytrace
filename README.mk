## How to use:

```

make
./test | awk '{print $1}' | xargs -n1 addr2line -e test

```
