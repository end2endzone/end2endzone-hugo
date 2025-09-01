function insertLineNumbersInCodeBlock(element_id) {
  // Grab the element
  const codeEl = document.getElementById(element_id);
  if (!codeEl) {
    console.error(`insertLineNumbersInCodeBlock: no element found with id "${element_id}"`);
    return;
  }

  // Make sure hljs is loaded
  if (typeof hljs === 'undefined') {
    console.error('insertLineNumbersInCodeBlock: hljs is not defined');
    return;
  }

  // Apply syntax highlighting
  hljs.highlightElement(codeEl);

  // Ensure the line numbering plugin is registered
  if (typeof hljs.lineNumbersBlock !== 'function') {
    console.error('insertLineNumbersInCodeBlock: hljs.lineNumbersBlock is not a function');
    return;
  }

  // Inject the line-number table
  hljs.lineNumbersBlock(codeEl);
}
