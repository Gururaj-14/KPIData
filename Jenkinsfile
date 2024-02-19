pipeline {
    agent{
	docker{
    image 'qt-image:latest'
}
}
    stages {
        stage('Checkout') {
            steps {
                //sh 'unzip *Code*.zip'
		git branch: "example", url: 'https://github.com/Gururaj-14/KPIData.git'
		sh 'cd plcsimulator'
		sh 'ls'
		sh 'pwd'
            }
        }
        stage('Clean') {
            steps {
		
                sh 'qmake -makefile'
            }
        }
        stage('Configure') {
            steps {
                 sh 'make'
            }
        }
        
        stage('Build') {
            steps {
                sh 'make clean'
            }
        }
        
        stage('Test') {
            steps {
                echo 'test'
            }
        }
        
        stage('Deploy') {
            steps {
                  echo 'Deploy'
            }
        }
    }
}
