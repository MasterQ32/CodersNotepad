#ifndef GENERICHIGHLIGHTER_HPP
#define GENERICHIGHLIGHTER_HPP

#include <QRegExp>
#include <QObject>
#include <QVector>
#include <QSyntaxHighlighter>

class GenericHighlighter :
		public QSyntaxHighlighter
{
	Q_OBJECT
private:
	struct HighlightingRule
	{
		QRegExp pattern;
		QTextCharFormat format;
	};
	struct BlockHighlightingRule
	{
		QRegExp patternStart;
		QRegExp patternEnd;
		QTextCharFormat format;
	};

	QVector<HighlightingRule> mRules;
	QVector<BlockHighlightingRule> mBlockRules;

public:
	explicit GenericHighlighter(QTextDocument *document = nullptr);
protected:
	void highlightBlock(const QString &text) override;
public:

	void addRule(const QRegExp &regex, const QTextCharFormat &format);

	void addBlockRule(const QRegExp &expStart, const QRegExp &expEnd, const QTextCharFormat &format);

signals:

public slots:
};

#endif // GENERICHIGHLIGHTER_HPP
