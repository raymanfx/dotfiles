# Import the bash extensions
# KEEP THIS AT THE TOP!
source ~/bash_extensions

# homebrew curl (with openssl)
export PATH=$(brew --prefix curl)/bin:$PATH

# Android SDK tools
export PATH="~/android-sdk/platform-tools:$PATH"

# Java 7 for Android
export JAVA_HOME=`/usr/libexec/java_home -v 1.8.0_102`

# ccache
export USE_CCACHE=1
export CCACHE_DIR=/Volumes/MacSSD/ccache

# Android build environment (Mac OS)
export BUILD_MAC_SDK_EXPERIMENTAL=1
export LC_CTYPE=C
export LANG=C

# Mac OS Hax
function setjdk() {
  if [ $# -ne 0 ]; then
    removeFromPath '/System/Library/Frameworks/JavaVM.framework/Home/bin'

  if [ -n "${JAVA_HOME+x}" ]; then
    removeFromPath $JAVA_HOME
  fi

  export JAVA_HOME=`/usr/libexec/java_home -v $@`
  export PATH=$JAVA_HOME/bin:$PATH

  fi
}
