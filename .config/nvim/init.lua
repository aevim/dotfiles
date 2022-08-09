local o = vim.o
o.expandtab = true
o.smartindent = true
o.tabstop = 2
o.shiftwidth = 2
o.number = true
o.termguicolors = true
vim.g.mapleader = " " 

vim.g.catppuccin_flavour = "mocha" -- latte, frappe, macchiato, mocha

require("catppuccin").setup()

vim.cmd [[colorscheme catppuccin]]

vim.api.nvim_set_keymap("n", "<leader>ff", ":Telescope find_files<CR>", { noremap = true })
vim.api.nvim_set_keymap("n", "<leader>fb", ":Telescope buffers<CR>", { noremap = true })
vim.api.nvim_set_keymap("n", "<leader>nn", ":NvimTreeToggle<CR>", { noremap = true })
vim.api.nvim_set_keymap("n", "<leader>tt", ":vsplit | term<CR>", { noremap = true })
vim.api.nvim_set_keymap("n", "<leader>gp", ":gp<CR>", { noremap = true })
vim.api.nvim_set_keymap("n", "<leader>gn", ":gn<CR>", { noremap = true })
vim.api.nvim_set_keymap("n", "<leader>gd", ":gd<CR>", { noremap = true })
vim.api.nvim_set_keymap('n', '<leader>h', ':FocusSplitLeft<CR>', { silent = true })
vim.api.nvim_set_keymap('n', '<leader>j', ':FocusSplitDown<CR>', { silent = true })
vim.api.nvim_set_keymap('n', '<leader>k', ':FocusSplitUp<CR>', { silent = true })
vim.api.nvim_set_keymap('n', '<leader>l', ':FocusSplitRight<CR>', { silent = true })
vim.api.nvim_set_keymap('n', '<leader>d', '<C-w><C-c>', { silent = true })
vim.api.nvim_set_keymap('t', '<Esc>', '<C-\\><C-n>', { silent = true })
