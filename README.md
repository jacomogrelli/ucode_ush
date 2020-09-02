### ucode_ush
### ush (u - ucode, sh - shell)

![image](https://github.com/jacomogrelli/ucode_ush/blob/master/ush_screenshot.png?raw=true)

This is simple command line interpreter for Unix written in C.

**Developers**
[Oleksiy Nechaiev](https://github.com/jacomogrelli)
[Yaroslav Pratsyovitiy](https://github.com/Eimer)

Use `make` or `make ush` to install and `./ush` to start shell.
`make uninstall` - uninstall shell
`make reistall` - uninstall & install shell

**ush** implements builtin commands:
- `export`
- `unset`
- `exit`
- `env` with `-i`, `-P`, `-u`
- `cd`  with `-s`, `-P`  and `-` argument
- `pwd` with `-L`, `-P`
- `which` with `-a`, `-s`
- `echo` with `-n`, `-e`, `-E`

If command is not found among builtin ones, ush searches for
needed binary file in folders, specified by `$PATH` variable.

Shell manages signals `CTRL+D`, `CTRL+C`. `CTRL+V`
and command separator `;`

These characters are escaped to be used literally:
`space`, `'`, `"`, `$`, `(`, `)`, `\\`, `{`, `}`.

Ush manages tilde expansion `~`, the basic form of parameter
expansion `${parameter}`
