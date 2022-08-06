-- This file can be loaded by calling `lua require('plugins')` from your init.vim

-- Only required if you have packer configured as `opt`
vim.cmd [[packadd packer.nvim]]

return require('packer').startup(function(use)
  -- Packer can manage itself
  use 'wbthomason/packer.nvim'

  use {
  'kyazdani42/nvim-tree.lua',
  requires = {
    'kyazdani42/nvim-web-devicons', -- optional, for file icons
  },
  tag = 'nightly', -- optional, updated every week. (see issue #1193)
  config = function() require("nvim-tree").setup() 
  end 
  }

  use {
  'nvim-telescope/telescope.nvim', tag = '0.1.0',
  requires = { {'nvim-lua/plenary.nvim'} }
  }

  use {'nvim-telescope/telescope-fzf-native.nvim', run = 'make', 
  config = function() require('telescope').setup{
    defaults =  { 
      file_ignore_patterns = { "node_modules" } 
      } 
    } 
  end 
  }

  use {
  'nvim-lualine/lualine.nvim',
  requires = { 'kyazdani42/nvim-web-devicons', opt = true },
  config = function() require('lualine').setup{
    options = { theme = 'catppuccin' }
  } 
  end 
  }

  use { "catppuccin/nvim", as = "catppuccin" }

  use { "beauwilliams/focus.nvim", config = function() require("focus").setup() end }
end)
