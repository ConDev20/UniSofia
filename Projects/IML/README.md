# IML
### Project Overview
IML is a simple markup language consisting of tags and attributes. The user can perform different operations on a list of comparable data (positive and negative fractional numbers). For now there are **3 categories of tags** .
### Map category
* <MAP-INC "N"> and <MAP-MLT "N">
```
<MAP-INC "1">1 2 3</MAP-INC> ⇒ 2 3 4
<MAP-MLT "2">1 2 3</MAP-MLT> ⇒ 2 4 6
```
### Aggregate category
* \<AGG-SUM>, \<AGG-PRO>, \<AGG-AVG>, \<AGG-FST>, \<AGG-LST>
```
  <AGG-SUM>1 2 3</AGG-SUM> ⇒ 6
  <AGG-PRO>1 2 3</AGG-PRO> ⇒ 6
  <AGG-AVG>1 2 3</AGG-AVG> ⇒ 2
  <AGG-FST>1 2 3</AGG-FST> ⇒ 1
  <AGG-LST>1 2 3</AGG-LST> ⇒ 3
```
### Sorting category
* \<SRT-REV>, \<SRT-ORD "ARG">, <SRT-SLC "N">, \<SRT-DST> <br/>
`<SRT-REV>1 2 3</SRT-REV> ⇒ 3 2 1`  _reverses the list_ <br/>
`<SRT-ORD "ASC">3 2 1</SRT-ORD> ⇒ 1 2 3`  _sorts the list in ascending or descending order_ <br/>
`<SRT-SLC "1">3 2 1</SRT-SLC> ⇒ 2 1`  _returns sublist from the given index onward_ <br/>
`<SRT-DST>4 8 4 3</SRT-DST> ⇒ 4 8 3`  _removes duplicates_ <br/>
### Grammar
```
  expression ::= (Tag_expression|value), (expression |  "")
  Tag_expr ::= open_tag, [expression], close_tag
  value ::= number
  open_tag ::= "<", string, [attribute], ">"
  close_tag ::= "<", "/" , string, ">"
  atribute ::= ' " ', value | string ,' " '
```
### How to use
`Interpreter program("input","output")` Accepts 2 file paths. If the program runs correctly, the result should be printed in the output file.
### Exemples
`<SRT-ORD "ASC"> 81 3 <MAP-INC "1"> 4 12 55 <AGG-AVG> 4 8 </AGG-AVG></MAP-INC>22</SRT-ORD>` <br/>
_output ⇒ 3 5 7 13 22 56 81_ <br/>
`<SRT-DST><SRT-SLC "3">57 18 9<MAP-INC "-3">4 2 2</MAP-INC>5</SRT-SLC></SRT-DST>` <br/>
_output ⇒ 1 -1 5_