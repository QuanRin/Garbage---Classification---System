$requirement = "requirement.txt"
$model = ".\model.h5"
$url = "https://drive.usercontent.google.com/download?id=1f23yibPY479TOhRBJrPYCFjmGWMbElnQ&export=download&authuser=0&confirm=t&uuid=6b82e1bb-0d77-4dcc-9097-8489a61bf5e5&at=APZUnTVqSF_vTWUJ5mhmotGD2KyN:1702780983587"
pip install -r $requirement
Remove-Item -Path ".\model.*" -Force
Invoke-WebRequest -Uri $url -OutFile $model -UseBasicParsing -SkipCertificateCheck

if ($?) {
    Write-Host "Download successful!"

} else {
    Write-Host "Error: Download failed."
}
