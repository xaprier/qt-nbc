pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                cmakeBuild(
		  installation: 'InSearchPath',
		  buildDir: 'build',
		  steps: [
			[envVars: 'DESTDIR=${WORKSPACE}/artifacts']
		  ]
		)
            }
        }
    }
}
