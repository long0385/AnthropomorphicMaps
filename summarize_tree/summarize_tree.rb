#!/user/bin/ruby

require 'find'

Find.find(ARGV[0]) do |path|
  if FileTest.executable?(path)
    puts path
  end
end
