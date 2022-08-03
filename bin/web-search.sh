#!/bin/bash
engine=$1
shift
# Escape spaces for URL
a="$*"
q=${a// /+}

case "$engine" in
    s) req="https://duckduckgo.com/?q=$q";;
    g) req="https://google.com/search?q=$q";;
    l) req="https://google.com/search?q=$q&btnI=";;
    w) req="https://en.wikipedia.org/w/index.php?title=Special:Search&search=$q&go=Go";;
    d) req="https://dictionary.reference.com/browse/$q";;
    # Add many more, then chose a default below:
    *) $0 l $engine $@; exit 0;;
esac

w3m -dump "$req" | more
