FROM debian

RUN apt-get update \
    && apt-get install -y --no-install-recommends python3 python3-django \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /usr/src/app
COPY . .

EXPOSE 8000
CMD ["python3", "./src/manage.py", "runserver", "0.0.0.0:8000"]
