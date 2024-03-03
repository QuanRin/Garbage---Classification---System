### Requirements:

*   #### Windows
    
    + Make sure WSL is installed
  
    + Run ```./run.ps1```

    + To access server from other devices within local network, you need to change WSL port forward [this](https://learn.microsoft.com/en-us/windows/wsl/networking)

*   #### Mac

    * Make sure virtual env is installed, wget, unzip also required
  
    * Run __run.sh__ file ```chmod 755 ./run.sh ; sh ./run.sh``` 

    * Or Download model directly from [this](https://drive.google.com/drive/folders/1ZtWU8fJB8nI16NkN4mavjut6a5kPCNLl?usp=sharing) then extract inside root folder

### Run:

+ Activate vitual env ```./bin/activate``` 
+ Run server ```python3 -m flask  run --host=0.0.0.0``` or ```flask run --host=0.0.0.0```
