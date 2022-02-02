
Set up for Environment is in Dockerfile
Run the following:
docker build -t appletest .
docker run -p 18080:18080 -d --rm appletest

Todo:
Figure out how to speed up build time (currently around 5 minutes)