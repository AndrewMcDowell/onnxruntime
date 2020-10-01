#!/bin/bash

python3 ort_build_latest.py

if [ -z "$1" ]
then
    DATE=$(date +"%m-%d-%Y-%H-%M")
    #DATE=$(date +"%m-%d-%Y %r")
else
    DATE=$1
fi

# many models 
if [ "$1" == "many-models" ]
then
    python3 benchmark.py -r validate -m /home/hcsuser/mount/ -o result/$DATE/many_models -e /home/hcsuser/perf/failing_model_list.json
    python3 benchmark.py -r benchmark -i random -t 10 -m /home/hcsuser/mount -o result/$DATE/many_models -e /home/hcsuser/perf/failing_model_list.json
fi

# ONNX model zoo
if [ "$1" == "onnx-models" ]
then
    python3 benchmark.py -r validate -m model_list.json -o result/$DATE/onnx_model_zoo
    python3 benchmark.py -r benchmark -i random -t 10 -m model_list.json -o result/$DATE/onnx_model_zoo
fi

# 1P models 
if [ "$1" == "partner-models" ]
then
    python3 benchmark.py -r validate -m /home/hcsuser/perf/partner_model_list.json -o result/$DATE/partner_models
    python3 benchmark.py -r benchmark -i random -t 10 -m /home/hcsuser/perf/partner_model_list.json -o result/$DATE/partner_models
fi
