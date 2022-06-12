#/bin/bash

to_study=$1
dir=$(pwd)

if [[ -z "$to_study" ]]; then
  echo 'Please, add a name!'
  exit 1
fi

isCreated() {
  (cd ~/.canki; ls $to_study >> /dev/null 2>&1 ; cd $dir) || touch ~/.canki/$to_study.txt
}

echo "Question: "  
read question  

echo "Answer: "
read answer

isCreated
echo "${question}; ${answer};" >> ~/.canki/$to_study.txt 

