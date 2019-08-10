cd ft-rails && sudo docker build -t ft-rails:on-build .
cd .. && sudo docker build -t ex02 .
sudo docker run -t --rm -p 3000:3000 ex02
