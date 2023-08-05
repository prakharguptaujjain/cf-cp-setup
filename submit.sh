main() {
    total_que=0
    curr_path=$(dirname "$(realpath "$0")")
    folder_within=$(basename "$curr_path")

    from_path=""
    contest_path=$(dirname $(dirname $(dirname $(dirname "$curr_path"))))
    folder_within_upper=${folder_within^^}  # Convert folder_within to uppercase

    for file in "$contest_path"/*.cpp; do
        if [[ -f "$file" && ${file##*/} == "$folder_within_upper"*.cpp ]]; then
            from_path="$file"
            break
        fi
    done

    if [[ -z "$from_path" ]]; then
        echo "No cpp file found from CPH"
        return
    fi

    to_path=$(dirname "$curr_path")/"$folder_within/$folder_within.cpp"
    echo "$from_path" "$to_path"

    cp "$from_path" "$to_path"

    # run submit
    cd "$curr_path"
    C:/Users/prakh/Desktop/Mimir/CP/cf_tools/cf.exe submit 2>&1

    echo "$result"
}

main
