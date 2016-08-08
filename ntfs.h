#!/bin/sh

mode=$1
volume=$2
volume_path=/Volumes/$volume
fstype="ntfs"
user=$(whoami)

if ! [ "$mode" == "rw" ] && ! [ "$mode" == "ro" ]; then
  echo "First argument is invalid!"
  echo "It should be one of the following:"
  echo "  [0] ro"
  echo "  [1] rw"
  echo "\n"
  exit 1
fi

if [ "$volume" == "" ]; then
  echo "Second argument is invalid!"
  echo "You must provide the volume name here, for example:"
  echo "  [0] MyNTFSDisk (no whitespaces)"
  echo "  [1] My\ NTFS\ Disk (with whitespaces)"
  echo "\n"
  exit 1
fi

if ! [ -e "$volume_path" ]; then
  echo "Cannot mount/unmount $path because it does not exist!"
  echo "Quitting.."
  echo "\n"
  exit 1
fi

volume_node=$(mount | grep $fstype | grep $volume_path | cut -d" " -f1)

ntfsrw() {
  diskutil unmount $volume_path
  sudo mkdir -p $volume_path
  sudo mount -t $fstype -o rw,nobrowse $volume_node $volume_path
  sudo chmod 755 $volume_path
  sudo chown $user:staff $volume_path
  ln -s $volume_path ~/Desktop/$volume
}

ntfsro() {
  sudo umount $volume_path
  if [ -e "$volume_path" ]; then
    sudo rm -r $volume_path
  fi
  rm ~/Desktop/$volume
  diskutil mount $volume_node
}

if [ "$mode" == "rw" ]; then
  ntfsrw
  exit 1
elif [ "$mode" == "ro" ]; then
  ntfsro
  exit 1
fi
