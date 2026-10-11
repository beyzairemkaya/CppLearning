 When we use a built-in array as a
function parameter:
• The complete array is not
copied.
• The array expression is
converted to a pointer to its
first element.
• The pointer is passed by
value.
• The function receives a copy of a
pointer to the first element, not a
copy of the entire array