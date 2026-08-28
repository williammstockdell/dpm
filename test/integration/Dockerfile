FROM ubuntu:24.04 AS builder

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        g++-14 \
        liblog4cxx-dev \
        libexpat1-dev \
        libssl-dev \
        libapr1-dev \
        libaprutil1-dev \
        make \
        ca-certificates && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /src
COPY . /src

ENV DPM_BUILD_DIR=/src

RUN make \
        DPM_BUILD_DIR=/src \
        DPM_INSTALL_DIR=/tmp/dpm_install \
        LN=ln \
        all \
 && make \
        DPM_BUILD_DIR=/src \
        DPM_INSTALL_DIR=/tmp/dpm_install \
        LN=ln \
        install

FROM ubuntu:24.04

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        liblog4cxx15 \
        libexpat1 \
        libssl3 \
        libapr1 \
        libaprutil1 \
        libstdc++6 \
        ca-certificates && \
    rm -rf /var/lib/apt/lists/*

COPY --from=builder /tmp/dpm_install/ /opt/dpm/

ENV PATH="/opt/dpm/bin:/opt/dpm/sbin:${PATH}"
WORKDIR /opt/dpm
