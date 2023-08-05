CONTEST_CODE=-1

main() {
    read -p "Enter contest code: " CONTEST_CODE
    echo "Contest code is: $CONTEST_CODE"
    # Check if the JSON file exists and read its content
    existing_code=""
    if [ -f "contest_code.json" ]; then
        existing_code=$(grep -oP '(?<=contest_code": ).*(?=})' contest_code.json)
    fi
    
    # Convert existing_code to an integer (if it's not empty)
    existing_code=$(printf '%d' "$existing_code" 2>/dev/null)
    
    # Compare the existing_code with CONTEST_CODE
    if [ "$existing_code" -eq "$CONTEST_CODE" ]; then
        echo "Contest code is the same as last time"
        exit 0
    fi
    rm -f *.cpp

    
    # Write the new contest code to the JSON file
    echo "{\"contest_code\": $CONTEST_CODE}" > contest_code.json
    
    
    echo "{\"contest_code\": $CONTEST_CODE}" > contest_code.json
    
    # run cf race CONTEST_CODE
    result=$(./cf.exe race "$CONTEST_CODE" 2>&1)
    
    echo "$result"
    
    # question dir
    que_dir=$(realpath "./cf/contest/$CONTEST_CODE")
    for que_path in "$que_dir"/*; do
        if [ -d "$que_path" ]; then
            # copy submit.sh to que_path
            cp submit.sh "$que_path"
        fi
    done
    
}

main
