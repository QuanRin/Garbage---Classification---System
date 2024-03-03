#!/bin/bash
zip_file="model.zip"
requirement="requirement.txt"
pip3 install -r "$requirement"
rm -f ./model*
wget --no-check-certificate "https://drive.usercontent.google.com/download?id=1f23yibPY479TOhRBJrPYCFjmGWMbElnQ&export=download&authuser=0&confirm=t&uuid=6b82e1bb-0d77-4dcc-9097-8489a61bf5e5&at=APZUnTVqSF_vTWUJ5mhmotGD2KyN:1702780983587" -O "$zip_file"
if [ $? -eq 0 ]; then
    echo "Download successful!"
else
    echo "Error: Download failed."
fi
