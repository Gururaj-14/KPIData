pipeline {
    agent {
        docker {
            image 'ubuntu_for_qt:latest'
        }
     }
    stages {
        stage('Checkout') {	
            steps {
		sh 'ls'
		sh'pwd'
		    
                //sh 'unzip *Code*.zip'
		sh 'pwd'
		sh 'cd plcsimulator'
		sh 'pwd'
		sh 'ls'
		sh 'pwd'
		}
            }
        }
        stage('Clean') {
            steps {
		sh 'pwd'
                sh 'cd plcsimulator/ && qmake -makefile'
		}
            }
        }
        stage('Configure') {
            steps {
                 sh 'cd plcsimulator/ && make'
            }
        }
        
        stage('Build') {
            steps {
                sh 'cd plcsimulator/ && make clean'
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
