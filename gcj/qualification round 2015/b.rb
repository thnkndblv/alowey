ntc = gets.to_i

(1 .. ntc).each do |tc|
  n = gets.to_i
  arr = gets.split.map &:to_i
  max_h = arr.max

  ans = nil

  (1 .. max_h).each do |h|
    count = h

    arr.each do |pan|
      count += ((pan + h - 1) / h) - 1 if pan > h
    end

    ans = ans.nil? ? count : [ans, count].min
  end

  puts "Case \##{tc}: #{ans}"
end