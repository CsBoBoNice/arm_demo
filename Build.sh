#!/bin/bash



pwd_dir="$(pwd)"
build_dir="build/"
make_cores_number="-j4"

function usage()
{
    echo "Usage:"
    echo "      ./build.sh [OPTION]"
    echo "OPTION: "
    echo "      x86/X86: build x86's platform app"
    echo "      arm/ARM: build arm's platform app"
    echo "      clean: make clean"
    echo "      make: make xag_router_main"
    exit 0
}

function except_exit()
{
    echo "error! exit"
    exit 1
}

function open_build_dir()
{
    if [ -e $1 ]
    then
        cd $1
    else 
        mkdir -p $1
        cd $1
    fi
}


function build_x86()
{
    echo "build x86..."
    open_build_dir $build_dir || except_exit
    cmake .. || except_exit
    make $make_cores_number
    echo "build x86 Success!"
}

function build_arm()
{
    echo "build arm..."
    open_build_dir $build_dir || except_exit
    cmake .. -DCMAKE_C_COMPILER=aarch64-linux-gnu-gcc-9 \
    -DCMAKE_CXX_COMPILER=aarch64-linux-gnu-g++-9 \
    -DCMAKE_BUILD_TYPE=Release || except_exit
    make $make_cores_number
    echo "build arm Success!"
}

function rebuild()
{
    echo "make clean"
    cd $build_dir || except_exit
    #make clean
    make $make_cores_number
    echo "rebuild Success!"
}

function clean()
{
    echo "make clean"
    cd $build_dir || except_exit
    pwd
    rm ./* -rv

    echo "clean Success!"
}

function main_run()
{
    if [ $# -ne 1 ]
    then
        usage
    fi
    local prama="$1"

    case "${prama}" in
        x86|X86)
            build_x86
            ;;
        arm|ARM)
            build_arm
            ;;
        clean)
            clean
            ;;
        rebuild)
            rebuild
            ;;
        usage)
            usage
            ;;
        -h|--help)
            usage
            ;;
    esac
}

main_run $@
