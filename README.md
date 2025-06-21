# yardnsm's QMK Userspace

This is my QMK userspace repository with my own personal keymaps for my custom keyboards.

## Configuring Locally

```bash
$ qmk setup
$ git clone https://github.com/yardnsm/qmk_userspace
$ cd qmk_userspace
$ qmk config user.overlay_dir="$(realpath .)"
```

## Compiling Locally

### Lily58

```bash
qmk compile -kb lily58/rev1 -km via_sodmo_hmr
# or
make lily58/rev1:via_sodmo_hmr

# flashing
qmk flash -kb lily58/rev1 -km via_sodmo_hmr
# or
make lily58/rev1:via_sodmo_hmr:flash
```

## Compiling in GitHub Actions

```bash
qmk userspace-add -kb lily58/rev1 -km via_sodmo_hmr
qmk userspace-list
```
