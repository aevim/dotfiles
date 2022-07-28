-- This file can be loaded by calling `lua require('plugins')` from your init.vim

-- Only required if you have packer configured as `opt`
vim.cmd [[packadd packer.nvim]]

local o = vim.o
o.expandtab = true
o.smartindent = true
o.tabstop = 2
o.shiftwidth = 2
o.number = true
o.termguicolors = true
vim.g.mapleader = " " 

vim.cmd 'colorscheme spaceduck'
vim.api.nvim_set_keymap("n", "<leader>ff", ":Telescope find_files<CR>", { noremap = true })
vim.api.nvim_set_keymap("n", "<leader>fb", ":Telescope buffers<CR>", { noremap = true })
vim.api.nvim_set_keymap("n", "<leader>nn", ":NvimTreeToggle<CR>", { noremap = true })
vim.api.nvim_set_keymap("n", "<leader>tt", ":term<CR>", { noremap = true })
vim.api.nvim_set_keymap("n", "<leader>gp", ":gp<CR>", { noremap = true })
vim.api.nvim_set_keymap("n", "<leader>gn", ":gn<CR>", { noremap = true })
vim.api.nvim_set_keymap("n", "<leader>gd", ":gd<CR>", { noremap = true })
vim.api.nvim_set_keymap('n', '<leader>h', ':FocusSplitLeft<CR>', { silent = true })
vim.api.nvim_set_keymap('n', '<leader>j', ':FocusSplitDown<CR>', { silent = true })
vim.api.nvim_set_keymap('n', '<leader>k', ':FocusSplitUp<CR>', { silent = true })
vim.api.nvim_set_keymap('n', '<leader>l', ':FocusSplitRight<CR>', { silent = true })
-- To get fzf loaded and working with telescope, you need to call
-- load_extension, somewhere after setup function:
require('telescope').load_extension('fzf')
require('lualine').setup{
  options = { theme = 'spaceduck' }
}

return require('packer').startup(function()
  use {
  'kyazdani42/nvim-tree.lua',
  requires = {
    'kyazdani42/nvim-web-devicons', -- optional, for file icons
  },
  tag = 'nightly', -- optional, updated every week. (see issue #1193)
  config = function() require("nvim-tree").setup() 
  end }

  use {
  'nvim-telescope/telescope.nvim', tag = '0.1.0',
  requires = { {'nvim-lua/plenary.nvim'} }
  }

  use {'nvim-telescope/telescope-fzf-native.nvim', run = 'make', 
  config = function() require('telescope').setup{
    defaults =  { 
      file_ignore_patterns = { "node_modules" } } 
    } end }

  use {
  'nvim-lualine/lualine.nvim',
  requires = { 'kyazdani42/nvim-web-devicons', opt = true }
  }

  use {'pineapplegiant/spaceduck'}

  use { "beauwilliams/focus.nvim", config = function() require("focus").setup() end }
-- Or lazy load with `module` option. See further down for info on how to lazy load when using FocusSplit commands
-- Or lazy load this plugin by creating an arbitrary command using the cmd option in packer.nvim
-- use { 'beauwilliams/focus.nvim', cmd = { "FocusSplitNicely", "FocusSplitCycle" }, module = "focus",
--     config = function()
--         require("focus").setup({hybridnumber = true})
--     end
-- }
end)

