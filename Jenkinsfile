pipeline {
    agent any
environment {
        //DOCKER_REGISTRY = 'your-docker-registry-url'
        DOCKER_IMAGE = 'ubuntu_for_qt'
        WORKING_DIRECTORY = '\\ProgramData\\Jenkins\\.jenkins\\workspace\\plc_simulator@2'
    }
    stages {
        stage('Checkout') {
		agent 
		{
			docker
			{
				image "ubuntu_for_qt:latest"
				args "\\ProgramData\\Jenkins\\.jenkins\\workspace\\plc_simulator@2"
			}
		}
			
            steps {
		script{
		def containerId = sh(script: 'docker run -d ubuntu', returnStdout: true).trim()

		sh "docker exec -it ${containerId} ls -l"
		sh "docker exec -it ${containerId} git branch: "example", url: 'https://github.com/Gururaj-14/KPIData.git'"

		bat 'docker run ubuntu_for_qt:latest bash -c "echo Hello World"'
		
                //sh 'unzip *Code*.zip'
		bat "cd"
		bat "pwd"
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
}
