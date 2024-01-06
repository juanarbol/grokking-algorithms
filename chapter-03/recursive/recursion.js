'use strict'

// Writing this thing in C++ will be such a pain in the ass.
const fs = require('node:fs/promises')
const path = require('node:path')


// I want to open every folder in this repo and find this file.
async function printItself (filePath, fileType = 'folder') {
  // Base case, we reach this file
  if (fileType == 'file') {
    if (filePath.includes('recursive/recursion.js')) {
      const fileContent = await fs.readFile(filePath)
      console.log(fileContent.toString())
    }
    return null
  }

  // Ignore the git folder
  let files = await fs.readdir(filePath, { withFileTypes: true })
  files = files.filter(f => f.name !== '\.git')
  files.forEach(fileOrFolder =>
    // Recursive part, open every inner folder or file
    printItself(
      path.resolve(filePath,fileOrFolder.name),
      fileOrFolder.isDirectory() ? 'folder' : 'file'
    )
  )

  return 'Wait for it :) \n'
}

function main () {
  // Run this from the project root
  // node chapter-03/recursive/recursion.js
  const root = path.resolve(process.cwd())
  printItself(root).then(console.log)
}

main()
