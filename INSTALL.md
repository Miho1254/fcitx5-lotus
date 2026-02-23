# Hướng dẫn cài đặt fcitx5-lotus trên các distro: Arch, Fedora, Debian, OpenSUSE, Raspbian, Ubuntu

## Arch Linux

- Sửa file `/etc/pacman.conf` và thêm các dòng sau:

```
[home_iamnanoka_Arch]
Server = https://download.opensuse.org/repositories/home:/iamnanoka/Arch/$arch
```

- Sau đó chạy các lệnh dưới để cài đặt:

```bash
key=$(curl -fsSL https://download.opensuse.org/repositories/home:iamnanoka/Arch/$(uname -m)/home_iamnanoka_Arch.key)
fingerprint=$(gpg --quiet --with-colons --import-options show-only --import --fingerprint <<< "${key}" | awk -F: '$1 == "fpr" { print $10 }')
sudo pacman-key --init
sudo pacman-key --add - <<< "${key}"
sudo pacman-key --lsign-key "${fingerprint}"
sudo pacman -Sy home_iamnanoka_Arch/fcitx5-lotus
```

## Debian

### Debian Unstable

Chạy các lệnh sau:

```bash
echo 'deb http://download.opensuse.org/repositories/home:/iamnanoka/Debian_Unstable/ /' | sudo tee /etc/apt/sources.list.d/home:iamnanoka.list
curl -fsSL https://download.opensuse.org/repositories/home:iamnanoka/Debian_Unstable/Release.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/home_iamnanoka.gpg > /dev/null
sudo apt update
sudo apt install fcitx5-lotus
```

### Debian Testing

Chạy các lệnh sau:

```bash
echo 'deb http://download.opensuse.org/repositories/home:/iamnanoka/Debian_Testing/ /' | sudo tee /etc/apt/sources.list.d/home:iamnanoka.list
curl -fsSL https://download.opensuse.org/repositories/home:iamnanoka/Debian_Testing/Release.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/home_iamnanoka.gpg > /dev/null
sudo apt update
sudo apt install fcitx5-lotus
```

### Debian 13

Chạy các lệnh sau:

```bash
echo 'deb http://download.opensuse.org/repositories/home:/iamnanoka/Debian_13/ /' | sudo tee /etc/apt/sources.list.d/home:iamnanoka.list
curl -fsSL https://download.opensuse.org/repositories/home:iamnanoka/Debian_13/Release.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/home_iamnanoka.gpg > /dev/null
sudo apt update
sudo apt install fcitx5-lotus
```

### Debian 12

Chạy các lệnh sau:

```bash
echo 'deb http://download.opensuse.org/repositories/home:/iamnanoka/Debian_12/ /' | sudo tee /etc/apt/sources.list.d/home:iamnanoka.list
curl -fsSL https://download.opensuse.org/repositories/home:iamnanoka/Debian_12/Release.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/home_iamnanoka.gpg > /dev/null
sudo apt update
sudo apt install fcitx5-lotus
```

## Fedora

### Fedora Rawhide

Chạy các lệnh sau:

```bash
sudo dnf config-manager addrepo --from-repofile=https://download.opensuse.org/repositories/home:iamnanoka/Fedora_Rawhide/home:iamnanoka.repo
sudo dnf install fcitx5-lotus
```

### Fedora 43

Chạy các lệnh sau:

```bash
sudo dnf config-manager addrepo --from-repofile=https://download.opensuse.org/repositories/home:iamnanoka/Fedora_43/home:iamnanoka.repo
sudo dnf install fcitx5-lotus
```

### Fedora 42

Chạy các lệnh sau:

```bash
sudo dnf config-manager addrepo --from-repofile=https://download.opensuse.org/repositories/home:iamnanoka/Fedora_42/home:iamnanoka.repo
sudo dnf install fcitx5-lotus
```

## OpenSUSE

### Tumbleweed

Chạy các lệnh sau:

```bash
sudo zypper addrepo https://download.opensuse.org/repositories/home:iamnanoka/openSUSE_Tumbleweed/home:iamnanoka.repo
sudo zypper refresh
sudo zypper install fcitx5-lotus
```

### Leap 16

Chạy các lệnh sau:

```bash
sudo zypper addrepo https://download.opensuse.org/repositories/home:iamnanoka/16.0/home:iamnanoka.repo
sudo zypper refresh
sudo zypper install fcitx5-lotus
```

## Raspbian

### Raspbian 13

Chạy các lệnh sau:

```bash
echo 'deb http://download.opensuse.org/repositories/home:/iamnanoka/Raspbian_13/ /' | sudo tee /etc/apt/sources.list.d/home:iamnanoka.list
curl -fsSL https://download.opensuse.org/repositories/home:iamnanoka/Raspbian_13/Release.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/home_iamnanoka.gpg > /dev/null
sudo apt update
sudo apt install fcitx5-lotus
```

### Raspbian 12

Chạy các lệnh sau:

```bash
echo 'deb http://download.opensuse.org/repositories/home:/iamnanoka/Raspbian_12/ /' | sudo tee /etc/apt/sources.list.d/home:iamnanoka.list
curl -fsSL https://download.opensuse.org/repositories/home:iamnanoka/Raspbian_12/Release.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/home_iamnanoka.gpg > /dev/null
sudo apt update
sudo apt install fcitx5-lotus
```

## xUbuntu

### xUbuntu 25.10

Chạy các lệnh sau:

```bash
echo 'deb http://download.opensuse.org/repositories/home:/iamnanoka/xUbuntu_25.10/ /' | sudo tee /etc/apt/sources.list.d/home:iamnanoka.list
curl -fsSL https://download.opensuse.org/repositories/home:iamnanoka/xUbuntu_25.10/Release.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/home_iamnanoka.gpg > /dev/null
sudo apt update
sudo apt install fcitx5-lotus
```

### xUbuntu 25.04

Chạy các lệnh sau:

```bash
echo 'deb http://download.opensuse.org/repositories/home:/iamnanoka/xUbuntu_25.04/ /' | sudo tee /etc/apt/sources.list.d/home:iamnanoka.list
curl -fsSL https://download.opensuse.org/repositories/home:iamnanoka/xUbuntu_25.04/Release.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/home_iamnanoka.gpg > /dev/null
sudo apt update
sudo apt install fcitx5-lotus
```

### xUbuntu 24.04

Chạy các lệnh sau:

```bash
echo 'deb http://download.opensuse.org/repositories/home:/iamnanoka/xUbuntu_24.04/ /' | sudo tee /etc/apt/sources.list.d/home:iamnanoka.list
curl -fsSL https://download.opensuse.org/repositories/home:iamnanoka/xUbuntu_24.04/Release.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/home_iamnanoka.gpg > /dev/null
sudo apt update
sudo apt install fcitx5-lotus
```

### xUbuntu 22.04

Chạy các lệnh sau:

```bash
echo 'deb http://download.opensuse.org/repositories/home:/iamnanoka/xUbuntu_22.04/ /' | sudo tee /etc/apt/sources.list.d/home:iamnanoka.list
curl -fsSL https://download.opensuse.org/repositories/home:iamnanoka/xUbuntu_22.04/Release.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/home_iamnanoka.gpg > /dev/null
sudo apt update
sudo apt install fcitx5-lotus
```
