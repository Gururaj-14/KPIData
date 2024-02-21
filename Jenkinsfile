pipeline {
    agent any
	
    stages {
        stage('Checkout') {
		
            steps {
		bat "cd plcsimulator"
		bat 'docker run ubuntu bash -c "echo Hello World"'
		
                //sh 'unzip *Code*.zip'
		sh 'pwd'
		git branch: "example", url: 'https://github.com/Gururaj-14/KPIData.git'
		sh 'cd plcsimulator'
		sh 'pwd'
		sh 'ls'
		sh 'pwd'
		    }
            }
        }
        stage('Clean') {
            steps {
		    dir("C://ProgramData//Jenkins//.jenkins/workspace//plc_simulator//plcsimulator//"){
		sh 'pwd'
                sh 'qmake -makefile'
		    }
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
