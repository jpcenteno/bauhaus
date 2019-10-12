_bauhaus_prompt() {
    PS1="$(EXITCODE="$?" NJOBS="$(jobs | wc -l)" bauhaus)"
}
PROMPT_COMMAND=_bauhaus_prompt
