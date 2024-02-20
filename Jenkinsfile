pipeline {
    agent any//{
	//docker {
    	//	image 'ubuntu_for_qt:latest'
	//	args '-v C://ProgramData//Jenkins//.jenkins//workspace//qt_app://plcsimulator'
	//}
    //}
	
    stages {
        stage('Checkout') {
            steps {
		//git branch: 'your_branch_name', credentialsId: 'your_credentials_id', url: 'https://github.com/your_username/your_repository.git'
		sh 'docker run --rm -it ubuntu_for_qt'
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
