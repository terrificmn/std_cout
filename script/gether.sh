#!/bin/bash
param=$1
version=1.2.3

if [ ! -z $param ]; then
    if [ $param = "install" ]; then
        echo "install type"
        sudo mkdir -p /usr/local/lib/std_cout
        sudo mkdir -p /usr/local/lib/cmake/std_cout
        sudo mkdir -p /usr/local/include/std_cout

        sudo mv ./libstd_cout.so /usr/local/lib/std_cout
        sudo mv ./std_coutConfig.cmake /usr/local/lib/cmake/std_cout
        sudo mv ./std_coutConfigVersion.cmake /usr/local/lib/cmake/std_cout
        sudo mv ./std_coutTargets.cmake /usr/local/lib/cmake/std_cout
        sudo mv ./std_coutTargets-noconfig.cmake /usr/local/lib/cmake/std_cout
        sudo mv ./std_cout.hpp /usr/local/include/std_cout
        sudo mv ./std_cout.tpp /usr/local/include/std_cout

        echo "installation done:)"
    elif [ $param = "tar" ];then
        echo "tar"
        if [ ! -d "../build" ]; then
            echo "build directory is not found"
            exit
        fi
        mkdir ready-install
        cp ../build/libstd_cout.so ready-install/
        cp ../build/std_coutConfig.cmake ready-install/
        cp ../build/std_coutConfigVersion.cmake ready-install/
        cp ../build/CMakeFiles/Export/lib/cmake/std_cout/std_coutTargets.cmake ready-install/
        cp ../build/CMakeFiles/Export/lib/cmake/std_cout/std_coutTargets-noconfig.cmake ready-install/
        cp ../include/std_cout.hpp ready-install/
        cp ../include/std_cout.tpp ready-install/
        cp ./gether.sh ready-install/

        ### create a README.md
        filename=ready-install/README.md
        cat > $filename << END_LABEL
Once a tar file is extracted, go to the 'ready-install' directory, then please, execute a script.
\`\`\`
./gether.sh install
\`\`\`
You may remove the 'ready-install' directory after it's installed.
END_LABEL
# if indent is not fit but it's important for END_LABEL to start with the first line.

        tar Jcvfp std_cout_v${version}_ubuntu20.tar.xz ready-install/*
        rm -rf ./ready-install
        
        echo "tar Done:)"

    else 
        echo "wrong parameter"
        
    fi
    exit
fi

echo "tar or install"

