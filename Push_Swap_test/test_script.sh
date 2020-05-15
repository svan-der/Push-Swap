#!/bin/bash

GREEN='\033[0;32m'
YELLOW='\e[1;33m'
RED='\033[0;31m'
RESET='\033[0m'

# $1 is the first argument on the command line from where
# we get the the filename with our random numbers sequences
input="$1"

sort_quality () {
  x=`expr $1 + 0`
  y=`expr $2 + 0`
  # printf "$1 $hun $2 $med \n\n"
  if [ "$x" -eq 5 ] && [ "$y" -lt 9 ]
  then
    printf "$GREEN$y (< 9) $RESET"
  elif [ "$x" -eq 5 ] && [ "$y" -lt 13 ]
  then
    printf "$YELLOW$y (< 13) $RESET"
  elif [ "$x" -eq 5 ] && [ "$y" -gt 12 ]
  then
    printf "$RED$y (> 12) $RESET"
  elif [ "$x" -eq 100 ] && [ "$y" -lt 700 ]
  then
    printf "$GREEN$y (< 700) $RESET"
    let test_med_green++
  elif [ "$x" -eq 100 ] && [ "$y" -lt 900 ]
  then
    printf "$YELLOW$y (< 900) $RESET"
    let test_med_yellow++
  elif [ "$x" -eq 100 ] && [ "$y" -lt 1100 ]
  then
    printf "$RED$y (< 1100) $RESET"
  elif [ "$x" -eq 500 ] && [ "$y" -lt 5500 ]
  then
    printf "$GREEN$y (< 5500) $RESET"
    let test_big_green++
  elif [ "$x" -eq 500 ] && [ "$y" -lt 7000 ]
  then
    printf "$YELLOW$y (< 7000) $RESET"
    let test_big_yellow++
  elif [ "$x" -eq 500 ] && [ "$y" -lt 8500 ]
  then
    printf "$RED$y (< 8500) $RESET"
    let test_big_red++
  else
    printf "$y"
  fi
}

wc=0
counter=0
max_oper=0
max_test=0
test_med_yellow=0
test_med_green=0
test_big_yellow=0
test_big_green=0
test_big_red=0
while IFS= read -r line
do
  wc="$(./push_swap $line | wc -l)"
  # echo "$wc"
  # output="$(./push_swap $line | ./checker -n $line)"
  output="$(./push_swap $line | ./checker $line)"
  # echo "$line"
  # echo "$output"
  # count the amount of numbers the test was executed
  numbers=0
  for number in $line
  do
      let numbers++
  done
  # read each of the 2 lines that were printed after the test was executed
  # printf "\n$output\n"
  # printf "\n numbers = $numbers\n"
  while IFS= read -r linetest
  do
    cleanline=${linetest}
    # printf "\n cleanline = $cleanline\n"
    stringarray=($cleanline)
    # printf "\n cleanline = ${stringarray[4]}\n"
    if [ "$cleanline" == "OK" ] || [ "$cleanline" == "KO" ]
    then
      let counter++
      # operations=${linetest##* }
      operations=$wc
      if [ "$operations" -gt $max_oper ]
      then
        max_oper=$operations
        max_test=$counter
      fi
      if [ "$cleanline" == "OK" ]
      then
        printf "Test   $counter\t[$GREEN $cleanline $RESET]\tfor $numbers   random numbers with  "
        sort_quality "$numbers" "$operations"
        printf "   operations\n"
      elif [ "$cleanline" == "KO" ] || [ "$cleanline" == "Error" ]
      then
        printf "Test   $counter\t[$RED $cleanline $RESET]\tfor $numbers   random numbers with  $YELLOW $operations $RESET   operations\n"
        # echo $line
        ( echo $line ; echo "" ) >> errorlog.txt
      fi
    elif [ "$cleanline" == "Error" ]
    then
      status="Error"
      printf "Test   $counter\t[$RED $cleanline $RESET]\tfor $numbers   random numbers with  $YELLOW $operations $RESET   operations\n"
    else
      status="Undefined"
      printf "Test   $counter\t[$RED $cleanline $RESET]\tfor $numbers   random numbers with  $YELLOW $operations $RESET   operations\n"
      # exit 1
    fi
  done <<< "$output"
done < "$input"
printf "Max operations : $max_oper in Test $max_test\n"
printf "Yellow tests for 100 : $test_med_yellow\n"
printf "Green tests for 100 : $test_med_green\n"
printf "Red tests for 500 : $test_big_red\n"
printf "Yellow tests for 500 : $test_big_yellow\n"
printf "Green tests for 500 : $test_big_green\n"