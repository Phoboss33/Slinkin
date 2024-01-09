program Lab1;
uses SysUtils;
var
  input: string;
  val: Int64;
begin
  readln(input);
  Randomize;
  if input = 'Shortint' then
  begin
    val := Random(high(Shortint) - low(Shortint) + 1) + low(Shortint);
    writeln('Исследуемый тип: Shortint');
    writeln('Нижняя граница: ', low(Shortint));
    writeln('Верхняя граница: ', high(Shortint));
    writeln('Байт на переменную: ', sizeof(Shortint));
    writeln('Случайное значение: ', val);
    if val <> low(Shortint) then
      writeln('Предыдущее значение: ', pred(val))
    else
      writeln('Предыдущее значение: Overflow');
    if val <> high(Shortint) then
      writeln('Последующее значение: ', succ(val))
    else
      writeln('Последующее значение: Overflow');
  end
  else if input = 'SmallInt' then
  begin
    val := Random(high(SmallInt) - low(SmallInt) + 1) + low(SmallInt);
    writeln('Исследуемый тип: SmallInt');
    writeln('Нижняя граница: ', low(SmallInt));
    writeln('Верхняя граница: ', high(SmallInt));
    writeln('Байт на переменную: ', sizeof(SmallInt));
    writeln('Случайное значение: ', val);
    if val <> low(SmallInt) then
      writeln('Предыдущее значение: ', pred(val))
    else
      writeln('Предыдущее значение: Overflow');
    if val <> high(SmallInt) then
      writeln('Последующее значение: ', succ(val))
    else
      writeln('Последующее значение: Overflow');
  end
  else if input = 'Longint' then
  begin
    val := Random(high(Longint) - low(Longint) + 1) + low(Longint);
    writeln('Исследуемый тип: Longint');
    writeln('Нижняя граница: ', low(Longint));
    writeln('Верхняя граница: ', high(Longint));
    writeln('Байт на переменную: ', sizeof(Longint));
    writeln('Случайное значение: ', val);
    if val <> low(Longint) then
      writeln('Предыдущее значение: ', pred(val))
    else
      writeln('Предыдущее значение: Overflow');
    if val <> high(Longint) then
      writeln('Последующее значение: ', succ(val))
    else
      writeln('Последующее значение: Overflow');
  end
  else if input = 'Longword' then
  begin
    val := Random(high(Longword) - low(Longword) + 1) + low(Longword);
    writeln('Исследуемый тип: Longword');
    writeln('Нижняя граница: ', low(Longword));
    writeln('Верхняя граница: ', high(Longword));
    writeln('Байт на переменную: ', sizeof(Longword));
    writeln('Случайное значение: ', val);
    if val <> low(Longword) then
      writeln('Предыдущее значение: ', pred(val))
    else
      writeln('Предыдущее значение: Overflow');
    if val <> high(Longword) then
      writeln('Последующее значение: ', succ(val))
    else
      writeln('Последующее значение: Overflow');
  end
  else if input = 'Int64' then
  begin
    val := Random(high(Int64) - low(Int64) + 1) + low(Int64);
    writeln('Исследуемый тип: Int64');
    writeln('Нижняя граница: ', low(Int64));
    writeln('Верхняя граница: ', high(Int64));
    writeln('Байт на переменную: ', sizeof(Int64));
    writeln('Случайное значение: ', val);
    if val <> low(Int64) then
      writeln('Предыдущее значение: ', pred(val))
    else
      writeln('Предыдущее значение: Overflow');
    if val <> high(Int64) then
      writeln('Последующее значение: ', succ(val))
    else
      writeln('Последующее значение: Overflow');
  end
  else if input = 'Byte' then
  begin
    val := Random(high(Byte) - low(Byte) + 1) + low(Byte);
    writeln('Исследуемый тип: Byte');
    writeln('Нижняя граница: ', low(Byte));
    writeln('Верхняя граница: ', high(Byte));
    writeln('Байт на переменную: ', sizeof(Byte));
    writeln('Случайное значение: ', val);
    if val <> low(Byte) then
      writeln('Предыдущее значение: ', pred(val))
    else
      writeln('Предыдущее значение: Overflow');
    if val <> high(Byte) then
      writeln('Последующее значение: ', succ(val))
    else
      writeln('Последующее значение: Overflow');
  end
  else if input = 'Word' then
  begin
    val := Random(high(Word) - low(Word) + 1) + low(Word);
    writeln('Исследуемый тип: Word');
    writeln('Нижняя граница: ', low(Word));
    writeln('Верхняя граница: ', high(Word));
    writeln('Байт на переменную: ', sizeof(Word));
    writeln('Случайное значение: ', val);
    if val <> low(Word) then
      writeln('Предыдущее значение: ', pred(val))
    else
      writeln('Предыдущее значение: Overflow');
    if val <> high(Word) then
      writeln('Последующее значение: ', succ(val))
    else
      writeln('Последующее значение: Overflow');
  end
  else if input = 'Cardinal' then
  begin
    val := Random(high(Cardinal) - low(Cardinal) + 1) + low(Cardinal);
    writeln('Исследуемый тип: Cardinal');
    writeln('Нижняя граница: ', low(Cardinal));
    writeln('Верхняя граница: ', high(Cardinal));
    writeln('Байт на переменную: ', sizeof(Cardinal));
    writeln('Случайное значение: ', val);
    if val <> low(Cardinal) then
      writeln('Предыдущее значение: ', pred(val))
    else
      writeln('Предыдущее значение: Overflow');
    if val <> high(Cardinal) then
      writeln('Последующее значение: ', succ(val))
    else
      writeln('Последующее значение: Overflow');
  end
  else if input = 'QWord' then
  begin
    val := Random(high(QWord) - low(QWord) + 1) + low(QWord);
    writeln('Исследуемый тип: QWord');
    writeln('Нижняя граница: ', low(QWord));
    writeln('Верхняя граница: ', high(QWord));
    writeln('Байт на переменную: ', sizeof(QWord));
    writeln('Случайное значение: ', val);
    if val <> low(QWord) then
      writeln('Предыдущее значение: ', pred(val))
    else
      writeln('Предыдущее значение: Overflow');
    if val <> high(QWord) then
      writeln('Последующее значение: ', succ(val))
    else
      writeln('Последующее значение: Overflow');
  end
  else if input = 'Char' then
  begin
    val := Random(high(Char) - low(Char) + 1) + low(Char);
    writeln('Исследуемый тип: Char');
    writeln('Нижняя граница: ', '#', ord(low(Char)));
    writeln('Верхняя граница: ', '#', ord(high(Char)));
    writeln('Байт на переменную: ', sizeof(Char));
    writeln('Случайное значение: ', '#', val);
    if val <> ord(low(Char)) then
      writeln('Предыдущее значение: ', '#', pred(val))
    else
      writeln('Предыдущее значение: Overflow');
          if val <> ord(high(Char)) then
      writeln('Последующее значение: ', '#', succ(val))
    else
      writeln('Последующее значение: Overflow');
  end
  else if input = 'Boolean' then
  begin
    val := Random(2);
    writeln('Исследуемый тип: Boolean');
    writeln('Нижняя граница: ', low(Boolean));
    writeln('Верхняя граница: ', high(Boolean));
    writeln('Байт на переменную: ', sizeof(Boolean));
    writeln('Случайное значение: ', Boolean(val));
    if val <> 0 then
      writeln('Предыдущее значение: ', Boolean(val - 1))
    else
      writeln('Предыдущее значение: Overflow');
    if val <> 1 then
      writeln('Последующее значение: ', Boolean(val + 1))
    else
      writeln('Последующее значение: Overflow');
  end
  else
  begin
    writeln('Error');
  end;
end.
