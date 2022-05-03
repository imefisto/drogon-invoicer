FROM imefisto/invoicer_builder as builder

COPY . /code
WORKDIR /code

RUN rm -rf build \
  && mkdir build \
  && cd build \
  && cmake .. \
  && make

FROM imefisto/invoicer_common as runtime

WORKDIR /app
COPY --from=builder /code/build /app

EXPOSE 80

ENTRYPOINT ["./invoicer"]
