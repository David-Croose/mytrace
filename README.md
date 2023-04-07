## How to use:

```

make
./test 2>&1 | grep '0x' | awk '{print $1}' | xargs -r -n1 addr2line -e test

```

## Remember: this lib slow down your program!
