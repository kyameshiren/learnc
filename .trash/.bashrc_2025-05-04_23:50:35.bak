# Trash
TRASH="$HOME/.trash"
if [ ! -d "$TRASH" ]; then
    mkdir -p "$TRASH"
fi

# Alias
alias gitlog='git log --graph --oneline --all'
alias ls='ls -F --color=auto'
alias lc='clear && ls'
alias ll='ls -alF'
alias la='ls -aF'
alias rm="mv --backup=numbered --target-directory=\"$TRASH\""
alias cltrash="/bin/rm -rf /$HOME/.trash/*"
alias gitforce="git add . && git commit --amend --no-edit && git push --force"

# Set cd to auto-ls
function cd() {
        new_directory="$*";
        if [ $# -eq 0 ]; then
                new_directory="$HOME";
        fi;
        builtin cd "$new_directory" && ls --color=auto
}

# Set Prompt and Colors
function parse_git_branch() {
        git branch 2>/dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/[\1]/'
}

function new_line() {
        printf "\n$ "
}

export PS1="\[\033[1;31m\][\u@\h]\[\033[0m\]\w\[\033[1;31m\]\$(parse_git_branch) \[\033[0m\] $(new_line)"

# Set VIM
EDITOR=vim
export MANPAGER="/bin/sh -c \"col -b | vim -c 'set ft=man ts=8 nomod nolist noma' -\""
export MANWIDTH=80

# Set LS_COLORS
eval $(dircolors -b)
LS_COLORS=$LS_COLORS:'ow=1;34:' ; export LS_COLORS

# Start ssh-agent if it is not already running
if [ -z "$SSH_AGENT_PID" ]; then
    if [ -f ~/.ssh-agent-info ]; then
        source ~/.ssh-agent-info >/dev/null
    fi

    # Check if ssh-agent is running
    if ! ps -p $SSH_AGENT_PID > /dev/null 2>&1; then
        eval $(ssh-agent -s)
        echo "export SSH_AUTH_SOCK=$SSH_AUTH_SOCK" > ~/.ssh-agent-info
        echo "export SSH_AGENT_PID=$SSH_AGENT_PID" >> ~/.ssh-agent-info
    fi
fi
