# GIT

## Registrarse en GitLab 

www.gitlab.com 

## Instalar GIT en computadora 

www.git-scm.com 
Pasos: Next, next next, next, finish. Instalar por defecto. 

## Mandar Correo y/o usuario de GitLab

Mandar a p34035@correo.uia.mx 

## Habilitar Repositorio 

Les va a llegar un correo de que ya van a tener acceso a su repositorio. Entrar a GitLab y configura su equipo. 

## Configurar GIT local 

Abrir GitBash o CMD del equipo, realizar lo siguiente: 

* Git global setup 
```bash
git config --global user.name "Alfonso"
git config --global user.email "p34035@correo.uia.mx"
```
OJO: Aquí va su nombre y su correo con el que se registraron en GitLab 

* Create a new repository 
```bash
git clone https://gitlab.com/O2020METODOLOGIAA/UsuarioDePrueba.git  
```
OJO: Aqui va los datos de su repositorio, este es un ejemplo!! 
```bash
cd UsuarioDePrueba  
Type nul > test.txt 
git add test.txt  
git commit -m "archivo prueba" 
git push -u origin master 
```

* Push an existing folder / file (en orden)
```bash
git pull
git add .
git commit -m "test"
git push -u origin master
```

Preguntas frecuentes:
Puedo usar git en mi celular?
NO, no se puede. Hay cosas en la vida que NO se van a poder hacer nunca.
Van a ser programadores / desarrolladores, deben aprender a trabajar en su computadora y configurarla por ustedes mismos.
Si no cuentan con computadora, no van a poder hacer esto, y esto, es necesario y obligatorio.