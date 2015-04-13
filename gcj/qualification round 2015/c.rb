prod = {
  "1" => {
    "1" => "1",
    "i" => "i",
    "j" => "j",
    "k" => "k" 
  },
  "-1" => {
    "1" => "-1",
    "i" => "-i",
    "j" => "-j",
    "k" => "-k" 
  },
  "i" => {
    "1" => "i",
    "i" => "-1",
    "j" => "k",
    "k" => "-j"
  },
  "-i" => {
    "1" => "-i",
    "i" => "1",
    "j" => "-k",
    "k" => "j"
  },
  "j" => {
    "1" => "j",
    "i" => "-k",
    "j" => "-1",
    "k" => "i"
  },
  "-j" => {
    "1" => "-j",
    "i" => "k",
    "j" => "1",
    "k" => "-i"
  },
  "k" => {
    "1" => "k",
    "i" => "j",
    "j" => "-i",
    "k" => "-1"
  },
  "-k" => {
    "1" => "-k",
    "i" => "-j",
    "j" => "i",
    "k" => "1"
  }
}

ntc = gets.to_i

(1 .. ntc).each do |tc|
  len, tms = gets.split.map &:to_i
  str = gets.chomp * 4

  preff = ["1"]
  str.chars.each do |chr|
    preff << prod[preff.last][chr]
  end

  pieces = preff[1 .. -1].each_slice(len).to_a

  idx = tms % 4
  suff = (0 ... 4).map { |i| pieces[(idx + i) % 4] }.flatten

  i = preff.index "i"
  unless i.nil?
    i = nil if i >= len * tms
  end

  k = suff.rindex "k"
  unless k.nil?
    k = len * tms - (suff.length - k)
    k = nil if k < 0
  end

  if suff.last != "-1"
    puts "Case \##{tc}: NO"
  elsif i.nil? || k.nil?
    puts "Case \##{tc}: NO"
  elsif i > k
    puts "Case \##{tc}: NO"
  else
    puts "Case \##{tc}: YES"
  end
end
