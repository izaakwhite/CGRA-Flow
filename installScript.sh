#!/bin/bash
# WOULD NOT RECOMMEHD TO RUN THIS SCRIPT BUT IT DOES SHOWCASE WHAT YOU NEED TO INSTALL, USE IT AT YOUR OWN RISK
# Script must be ran with sudo
if [ "$EUID" -ne 0 ]; then
  echo "This script must be run as root. Please use sudo or run as root."
  exit 1
fi

# Check if the current directory is CGRA-FLOW
if [ "$(basename "$PWD")" != "CGRA-FLOW" ]; then
  echo "This script must be run from the CGRA-FLOW directory."
  exit 1
fi

# Function to check if a command exists
command_exists() {
    command -v "$1" &> /dev/null
}

# Check if Python 3.7 is installed
if command_exists python3.7; then
    echo "Python 3.7 is already installed."
else
    echo "Python 3.7 is not installed."

    # Check if Deadsnakes PPA is added
    if ! grep -q "deadsnakes" /etc/apt/sources.list /etc/apt/sources.list.d/*; then
        echo "Deadsnakes PPA is not found. Adding it now..."
        add-apt-repository ppa:deadsnakes/ppa -y
    else
        echo "Deadsnakes PPA is already added."
    fi

    # Update package list
    apt-get update

    # Install Python 3.7
    echo "Installing Python 3.7..."
    apt-get install python3.7 -y

    echo "Python 3.7 installation complete."
fi

# Update Submodules
git submodule update --init

# Make CGRA-Mapper
cd CGRA-Mapper && mkdir build && cd build && cmake ..
make
# Test for CGRA-Mapper
cd ../test # Should come from /build
ln -sf /usr/bin/opt-12 /usr/bin/opt && source compile.sh
cd ../..
# Test for verilator
echo ${VERILATOR_ROOT}
echo ${PYMTL_VERILATOR_INCLUDE_DIR}
verilator --version
#TEST VECTORCGRA
cd VectorCGRA
mkdir -p build && cd build
source ${HOME}/venv/bin/activate
pytest ../cgra/ -v --tb=short
#mflowgen dependcies
cd ../..
apt-get install -y yosys
cd tools/mflowgen
mkdir build && cd build
mflowgen run --design ../designs/GcdUnit
make 3
#cacti
cd ../../cacti
make
#sv2v (sysverilog to verilog)
cd ../sv2v
stack upgrade
make
#tkinter
apt-get install python3-tk
source ${HOME}/venv/bin/activate
pip install pillow
#should be done
cd ../..