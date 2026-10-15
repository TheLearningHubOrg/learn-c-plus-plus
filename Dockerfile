# Multi-stage Dockerfile for C++20 Systems Application
FROM alpine:3.20 AS builder

RUN apk add --no-cache build-base cmake

WORKDIR /app
COPY . .

RUN cmake -B build -S . && cmake --build build
RUN ./build/test_runner

FROM alpine:3.20 AS runner
WORKDIR /app
RUN apk add --no-cache libstdc++

COPY --from=builder /app/build/learn_cpp ./learn_cpp

ENTRYPOINT ["./learn_cpp"]
