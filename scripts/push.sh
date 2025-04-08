echo "commit message: "
read message

git add .

git commit -m "$message"

branch=$(git rev-parse --abbrev-ref HEAD)

git push origin "$branch"