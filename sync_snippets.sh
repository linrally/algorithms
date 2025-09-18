#!/usr/bin/env bash
# Copy repo UltiSnips snippets into Neovim global folder

mkdir -p ~/.config/nvim/UltiSnips
cp -r UltiSnips/* ~/.config/nvim/UltiSnips/

echo "Snippets synced to ~/.config/nvim/UltiSnips/"
