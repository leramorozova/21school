FROM ruby

RUN apt-get update -y && apt-get install -y build-essential libpq-dev ruby-bundler ruby-dev ruby-railties nodejs sqlite3 libsqlite3-dev

ONBUILD COPY app /opt/app
ONBUILD WORKDIR /opt/app
ONBUILD EXPOSE 3000
ONBUILD RUN mkdir ~/.ruby
ONBUILD RUN echo 'export GEM_HOME=~/.ruby/' >> ~/.bashrc
ONBUILD RUN echo 'export PATH="$PATH:~/.ruby/bin"' >> ~/.bashrc
ONBUILD RUN gem install sqlite3 -v '1.3.13'
ONBUILD RUN bundle update
ONBUILD RUN bundle install --path vendor/bundle
ONBUILD RUN rake db:migrate

# docker build -t ft-rails:on-build .
# app source: https://github.com/gothinkster/rails-realworld-example-app
