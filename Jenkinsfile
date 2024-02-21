pipeline {
	environment {
        DOCKER_IMAGE = 'ubuntu_for_qt'
        WORKING_DIRECTORY = '${WORKSPACE}'
    }
    		agent{
		docker {
		image "$DOCKER_IMAGE"
		}
		}

    stages {
        stage('Checkout') {
            steps {
		script{
			echo "${WORKSPACE}"
		// def dockerImage = docker.image("${DOCKER_IMAGE}")
  //                   dockerImage.inside("-v ${WORKING_DIRECTORY}:/app -w /app") {
		sh 'echo "Working directory mounted successfully"'

		//def containerId = sh(script: 'docker run -d ubuntu', returnStdout: true).trim()
		//sh "docker exec -it ${containerId} ls -l"
		//sh "docker exec -it ${containerId} git branch: "example", url: 'https://github.com/Gururaj-14/KPIData.git'"
		//bat 'docker run ubuntu_for_qt:latest bash -c "echo Hello World"'
		    }
		}
	   // }
	}
    }
}
