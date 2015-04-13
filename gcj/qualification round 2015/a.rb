ntc, = gets.split.map &:to_i

(1 .. ntc).each do |tc|
  ans = 0

  n, people = gets.split

  standing_peope = 0
  people
    .split('')
    .map(&:to_i)
    .each_with_index do |num_of_people, shyness_level|
      if standing_peope < shyness_level
        standing_peope += 1
        ans += 1
      end
      standing_peope += num_of_people
    end

  puts "Case \##{tc}: #{ans}"
end
